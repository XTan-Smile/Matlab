%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% AMP_block implementation for large size image.
% % ----------------------------------
% Key variables:
%      N:         the size of the input signal(image)
%      x:         vectorized original signal
%      n:         length of x
%      m:         number of measurements
%      T:         max number of iterations
%      tol:       stop criterion
%      L:         the number of blocks
%      mm:        # of measurements in each block
%      nn:        # of length of xx in each block
%      A_o:       measurement matrix in each block
%      Cx_wd:     components of WT of x
%      Lx_wd:     length of each level in WT of x
%      xx:        input signal for each block
%      yy:        measurement for each block
%      zz:        output residual of each block
%      xxhat:     estimation of xx
%      beta:      free parameter for tuning threshold, depending on std(y-A*xhat) 
%      cc & b:    tune threshold for easch block
%      errAmp:    MSE value
% ----------------------------------
% Last Upated:    July 8, 2015
% Author:         Xiao Tan
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear; close all;

% Large signal
N = 200;
I = imread('image/lenna256.bmp');
P = I(1:N,1:N,1);
P = P';
x = [];
for ii = 1:N
    x = [x P(ii,:)];
end
x = x';
x = double(x);
P = P';
% function xhat = AMP_block(N, x, tol)
% Dimensions of the problem
n = N*N;   % Signal length
m = N*N*0.5;    % Number of measurements
m = round(m);    % in case m is not int
% k = N*N/2;     % Number of non-zero elements 2k <= m, to ensure exact rectionstruction.
% Max number of iterations
T = 100;
% Tolerance
tol = 0;

%% Generate measurement matrix A_o
L = 10;
mm = m ./ L;
nn = n ./ L;
A_o = (1/sqrt(mm)).*randn(mm, nn);
%% Wavelet transform
[Cx_wd, Lx_wd] = wavedec(x, 6, 'db1');
%% Permutation
len_x = length(Cx_wd(:,1));
ind_pmt = randperm(len_x);
Cx_wd_pmt = Cx_wd(ind_pmt);
%% Initialization
xx = zeros(len_x./L, L);
for ii = 1:L
   xx(:,ii) = Cx_wd_pmt( (ii-1)*(len_x./L)+1 : ii*(len_x./L), 1 );
end
yy = A_o * xx;
h = figure;
% Initial estimate
beta = 1;
xxhat = zeros(nn, L);
zz = yy;
cc = zeros(L, 1);
for ii = 1:L
    cc(ii) = norm(zz(:,ii), 2)^2 ./ mm + var(yy(:,ii)-A_o * xxhat(:,ii));
end
errAmp = inf;
%% Block update
fprintf(1, 'AMP block update: \n');
for it = 1:T
    for ii = 1:L
%         xxhat_old = xxhat(:,ii);
        % Update the xhat
        gamma = xxhat(:,ii) + A_o'*zz(:,ii);
        threshold = sqrt(cc(ii)) .* sqrt(beta);
        xxhat(:,ii) = wthresh(gamma, 's', threshold);
        % Update the residual
        xNorm0 = length(nonzeros(xxhat(:,ii)));
        b = min(xNorm0./mm, (mm-1)./mm);
        zz(:,ii) = yy(:,ii) - A_o * xxhat(:,ii) + b.*zz(:,ii);
        % Update the threshold
        cc(ii) = cc(ii) .* b + var(yy(:,ii)-A_o*xxhat(:,ii));
        beta = std(yy(:,ii)-A_o*xxhat(:,ii)) * 0.05;    %%
    end
    %% drawing MSE or plot image
    errAmp_old = errAmp;
    errAmp = mean((xx-xxhat).^2);
    errAmp = mean(errAmp);
    fprintf(1, '[t=%4.d: MSE = %.4f]\n', it, errAmp);
    figure(h);
    plot(it, errAmp, 'b.');
    hold on;
    xlim([1 T]);
    title('Mean-Squared Error of Recovery');
    xlabel('Iteration');
    ylabel('E');
    drawnow;
    %% stop criterion
    if(errAmp <= tol)
        break;
    end
    if (errAmp_old*1.01 < errAmp)
        break;
    end
end
%% reconstruct P
% turn xxhat into a column vector
new_x = [];
for ii = 1:L
    new_x = [new_x xxhat(:,ii)'];
end
new_x = new_x';
% P^(-1)
xhat_wd = zeros(n, 1);
for ii = 1:n
    xhat_wd(ind_pmt(ii)) = new_x(ii);
end
% W^(-1)
xhat = waverec(xhat_wd,Lx_wd,'db1');
% turn xhat into an image
newP = [];
for ii = 1:N
    newP = [newP xhat(N*(ii-1)+1:N*ii,1)];
end
%% drawing figures
% showing the original image
figure
imagesc(P)
title('Original')
colormap gray
% showing reconstructed image2
figure
imagesc(newP)
title('Reconstructed');
colormap gray
% end

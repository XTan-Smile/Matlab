%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% AMP implementation for small size image, can be either time-domain or 
% wavelet-domain, determined by variable: time_wave.
% Both of the methods adopt iterative soft thresholding.
% ----------------------------------
% Key variables:
%      N:         the size of the input signal(image), <= 100
%      x:         vectorized original signal
%      n:         length of x
%      m:         length of y (measurement size)
%      T:         iteration times
%      tol:       stop criterion
%      A:         measurement matrix
%      y:         measurement
%      z:         output residual
%      xhat:      estimation of x
%      beta:      free parameter for tuning threshold, depending on std(y-A*xhat) 
%      c:         tune threshold
%      time_wave: ==1: use time-domain AMP; ==0: use wavelet-domain AMP
% ----------------------------------
% Last Upated:    July 8, 2015
% Author:         Xiao Tan
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% AMP for small size image
clear; close all;

% Sparse signal
N = 100;
I = imread('image/lena.png');
P = I(1:N,1:N,1);
P = P';
x = [];
for ii = 1:N
    x = [x P(ii,:)];
end
x = x';
x = double(x);
P = P';
% Dimensions of the problem
n = N*N;   % Signal length
m = N*N*0.8;    % Number of measurements
m = round(m);    % in case m is not int
% k = N*N/2;     % Number of non-zero elements
% Max number of iterations
T = 100;
% Tolerance
tol = 10^(-4);
% Generate measurement matrix
A = (1/sqrt(m)).*randn(m, n);
y = A*x;
%% AMP
fprintf(1, 'AMP: \n');
h = figure;
% Initial estimate
beta = 1;
xhat = zeros(n, 1);
z = y;
c = norm(z,2)^2 ./ m + var(y-A*xhat);
for it = 1:T
    %% Iterative updates
    time_wave_emd = 0;
    if (time_wave_emd == 1)
        time_version;
    elseif (time_wave_emd == 0)
        wavelet_version;
    else
        fprintf(1, 'Choose a valid method please...\n');
        pause;
    end
    % Stopping criterion
    if(norm(xhat-xhat_old)/norm(xhat_old) < tol)
        break;
    end
    draw_mse;
end
fprintf(1, '||xhat - xhat_old||./||xhat_old|| =  %.4f\n',...
            norm(xhat-xhat_old)./norm(xhat_old));
%% reconstruct P
newP = [];
for ii = 1:N
    newP = [newP xhat(N*(ii-1)+1:N*ii,1)];
end
%% showing the original image
figure
imagesc(P)
colormap gray
%% showing reconstructed image2
figure
imagesc(newP)
colormap gray
%% Compute MSE
% errAmp2 = mean((xhat - x).*(xhat - x));


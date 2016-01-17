%% wavelet_version

%% wavelet decomp: db1, 3-level
xhat_old = xhat;
[Cgamma, Lgamma] = wavedec(xhat + A'*z, 3, 'db1');
% beta = 0;
threshold = wavedec(sqrt(c) * sqrt(beta), 3, 'db1');
% sparse how: many elements near zero
xhat_wd = wthresh(Cgamma, 's', threshold(1));
% reconstruction
xhat = waverec(xhat_wd,Lgamma,'db1');
% residual: still calculated in time-domain
xNorm0 = length(nonzeros(xhat));
b = min(xNorm0./m, (m-1)./m);
z = y - A*xhat + b.*z;
% Update the threshold
c = c .* b;% + var(y-A*xhat);
beta = std(y - A*xhat) * 0.0005;%

%% wavelet decomp: db1, single level
% xhat_old = xhat;
% [gamma, gamma_d] = dwt(xhat + A'*z, 'db1');
%%% beta = 0;?
% threshold = dwt(sqrt(c) + sqrt(beta), 'db1');   %%
% xhat_ts = wthresh(gamma, 's', threshold);      %%
% xhat_d = wthresh(gamma_d, 's', threshold);  %% same thd?  What is the thd for details?
% % Update the residual
% xhat = idwt(xhat_ts, xhat_d, 'db1', n);
% xNorm0 = length(nonzeros(xhat));
% b = min(xNorm0./m, (m-1)./m);
% z = y - A*xhat + b.*z;
% % Update the threshold
% c = c .* b + var(y-A*xhat);
% beta = std(y - A*xhat);   %%% if need to * 50?

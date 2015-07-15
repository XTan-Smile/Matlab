xhat_old = xhat;
% Update the xhat
gamma = xhat + A'*z;
threshold = sqrt(c) + sqrt(beta);
% c
% threshold
xhat = wthresh(gamma, 's', threshold);
% Update the residual
xNorm0 = length(nonzeros(xhat));
b = min(xNorm0./m, (m-1)./m);
z = y - A*xhat + b.*z;
% Update the threshold
c = c .* b + var(y-A*xhat);
beta = std(y - A*xhat) * 50;    %%

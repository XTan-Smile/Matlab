function signM = derivative(lamda, grad, M)
% This function calculate the sub-gradient of l1-norm for the given matrix
% 'M', with parameter 'lamda'.
% 
% lamda: parameter
% grad: gradient without l1-norm penalty
% M: the given matrix
% 
% signM: sub-gradient of M
% 
% This function is called as:
% grad = grad + lamda .* derivative(lamda, grad, M);
% 
% (C) Margaret Tan, Duke University

if lamda <= 0
    signM = deri(M);
    return;
end
signM = M;
signM(find (M > 0)) = 1;
signM(find (M < 0)) = -1;
pro = find(M == 0);
N = length(pro);
if N < 1
    return;
end
for ii = 1:length(pro)
    if abs(grad(pro(ii))) < lamda
        signM(pro(ii)) = 0 - grad(pro(ii)) ./ lamda;
    elseif grad(pro(ii)) < 0 - lamda
        signM(pro(ii)) = 1;
    else
        signM(pro(ii)) = -1;
    end
end
end

function signM = deri(M)
    signM = M;
    signM(find(M >= 0)) = 1;
    signM(find(M < 0)) = -1;
end

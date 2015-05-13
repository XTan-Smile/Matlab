function [dist_sorted, index] = distM(givenPoint, X, M)
% This function calculate the distances between a given point 'givenPoint'
% and a set of points 'X' under a certain metric 'M'.
% 
% givenPoint: a given point 
% X: a set of points
% M: given metric
% 
% dist_sorted: descend sorted distance
% index: index of datapoints in X wrt dist_sorted
% 
% The input data X should be row vectors.
% 
% (C) Margaret Tan, Duke University

if length(X(1,:)) ~= length(M(1,:)) || ...
            length(M(1,:)) ~= length(M(:,1)) || ...
            length(length(givenPoint)) ~= length(M(:,1))
    error('Input data dimension error, please correct');
end
dataLen = length(X(:,1));
distances = zeros(dataLen, 1);
for ii = 1:dataLen
    mns = givenPoint - X(ii,:);
    distances(ii) = mns * M * mns';
end
[dist_sorted, index] = sort(distances, 'descend');
end

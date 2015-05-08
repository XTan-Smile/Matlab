function [trainM, testM, valiM] = scaling(train, test, vali)
% the input of this function needs to be row vectors, a.k.a. in each row,
% it is presenting the features for one data point.
%
% scaled = scaling(original_data_matrix)
%
% This function is used for scaling the input data by:
% scaled = (original - original_mean) / original_std
%
% (C) Margaret Tan, Duke University

ValF_len = 0;
TeF_len = 0;
TrF_len = 0;
trainM = [];
testM = [];
valiM = [];

if (nargin <= 2)
    vali = [];
end
if (nargin <= 1)
    test = [];
    trainM = train;
    return
end
if (isempty(vali) == 0)
    ValF_len = length(vali(:,1));
end
if (isempty(test) == 0)
    TeF_len = length(test(:,1));
end
TrF_len = length(train(:,1));

oriMtrx = [train' test' vali']';
    
N = length(oriMtrx(:,1));           % row
P = length(oriMtrx(1,:));           % column
% scale each feature
fmean = mean(oriMtrx, 1);           % take the mean of columns
fstd = std(oriMtrx, 1);             % take the std of columns
Mtrx = zeros(N, P);
for jj = 1:P
    if fstd(jj) ~= 0
        Mtrx(:,jj) = (oriMtrx(:,jj) - fmean(jj)) / fstd(jj);
    end
end
if (ValF_len ~= 0)
    valiM = oriMtrx(1+TrF_len+TeF_len : ValF_len+TrF_len+TeF_len,:);
end
if (TeF_len ~= 0)
    testM = Mtrx(1+TrF_len:TeF_len+TrF_len,:);
end
trainM = Mtrx(1:TrF_len,:);
end


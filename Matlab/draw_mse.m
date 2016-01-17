%% drawing MSE
errAmp2 = mean((x-xhat).^2);
fprintf(1, '[t=%4.d: MSE = %.4f]\n', it, errAmp2);
figure(h);
plot(it, errAmp2, 'b.');
hold on;
xlim([1 T]);
title('Mean-Squared Error of Recovery');
xlabel('Iteration');
ylabel('E');
drawnow;
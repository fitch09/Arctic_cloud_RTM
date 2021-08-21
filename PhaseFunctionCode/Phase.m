phase = readmatrix('phase.dat');

plot(phase(:,1),phase(:,3))

T = table(phase(:,1), phase(:,3))
writetable(T, 'phaseFunction.txt')

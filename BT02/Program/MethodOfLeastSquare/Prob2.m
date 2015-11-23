clear ; close all; clc
%%-----
temp = load('data.dat');
x = [ones(size(temp,1),1),temp(:,1)];
y = temp(:,2);
%%-----
theta = pinv(x'*x)*x'*y;
%%-----plot data-----
axis equal;
axis([min(x(:,2)),max(x(:,2)),min(y),max(y)]);
hold
scatter(x(:,2),y);
plot(x(:,2),x*theta);
legend('Data point', 'Regression Line', 'Location', 'NorthEastOutside');
clearvars

%%
data = [4 1.208e-06 5.42e-07 3.75e-07 3.25e-06; 8 8.34e-07 6.67e-07 8.75e-07 1.459e-06;
    16 3.167e-06 1.666e-06 2.542e-06 2.834e-06; 32 1.0708e-05 4.416e-06 8.209e-06 8e-06;
    64 3.8083e-05 1.45e-05 2.725e-05 1.6125e-05; 128 0.000148334 5.1667e-05 0.00010225 3.1792e-05;
    256 0.000840208 0.000223292 0.000394 7.9667e-05; 512 0.00230454 0.000697584 0.00114838 0.000139542;
    1024 0.00783996 0.00194321 0.003856 0.000277625; 2048 0.0218363 0.00560058 0.011056 0.000423417;
    4096 0.0859585 0.0223245 0.0438501 0.00095875; 8192 0.354036 0.090461 0.173597 0.00201571];
dim = data(:,1); % dimensione del vettore
tb = data(:,2); % tempi bubblesort
ti = data(:,3); % tempi insertionsort
ts = data(:,4); % tempi selectionsort
tstd = data(:,5); % tempi sort libreria standard

%figura: sovrappongo le c.c. al variare del tempo
figure('Name','Plot T(N)');
plot(dim, tb, 'LineWidth', 1.5); 
hold on;
plot(dim, ti, 'LineWidth', 1.5);
plot(dim, ts, 'LineWidth', 1.5);
plot(dim, tstd, 'LineWidth', 1.5);
xlabel('Vector dimension [N]');
ylabel('Time [s]');
legend('Bubblesort', 'Insertionsort', 'Selectionsort', 'Sort standard library')
title('Time c.c.')

% In questo grafico diventa evidente l'andamento quadratico dei 3 algoritmi
% proposti. Per la funzione sort della liberia standard, non si riconosce
% una crescita apprezzabile, per via delle dimensioni scelte. Tuttavia, si
% preferisce utilizzare questo plot (anziché in scala logaritmica) per
% poter apprezzare l'andamento quadratico di tb, ti, ts. Il grafico in
% scala logaritmica è riportato nel commento sottostante.


% figure('Name', 'Grafico T(N)');
% loglog(dim, tb, 'LineWidth', 1.5); 
% hold on;
% loglog(dim, ti, 'LineWidth', 1.5);
% loglog(dim, ts, 'LineWidth', 1.5);
% loglog(dim, tstd, 'LineWidth', 1.5);
% xlabel(['Dimensione del vettore [N]']);
% ylabel('Tempo [s]');
% legend('Bubblesort', 'Insertionsort', 'Selectionsort', 'Sort libreria standard')
% title('C.C. in tempo')
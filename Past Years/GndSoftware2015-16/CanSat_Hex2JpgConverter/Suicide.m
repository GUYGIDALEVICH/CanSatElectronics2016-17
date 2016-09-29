function [data] = Suicide(csvfile, csvfilename, n_comma, handles)

%  fclose ('all');
%  csvfile = fopen('22-Dec-2015 18_02_35.csv');
fullcsvfilename  =  strcat (csvfilename, '.csv');
data = textscan(fopen(fullcsvfilename), '%s');
data_str = data{1};
%mat_e = cell2mat (data_str(1));
t=0;
[A B] = size(data_str);
fileID = fopen('hex_data.txt' , 'w')
for i = 1:1:A
mat_e = cell2mat(data_str(i));
k = 1; commacount = 0;
Kappa = ones(1, A);

try
while (k < numel(mat_e)) %&& commacount<n_comma ) 
    d = mat_e (k);
    while (d ~= ',' && commacount<n_comma )
        t = t+1;
        k = k+1;
        d = mat_e(k);    
    end 
    
    if (d == ',')
           commacount = commacount + 1;
    end
    
    if (commacount == n_comma)
    buff = mat_e((k+1):numel(mat_e));
    else
        k = k+1;
    end
    
end
% imat = str2num (buff);
% Kappa(i,:) = imat;
% data = Kappa;
data = buff;
fprintf(fileID, data);

catch
end

end
fclose(fileID);
end

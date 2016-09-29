function [] = Update_GUItable(handles, table_filename, csvfile, csvfilename)

%takes the name of the most recent CSV file and displays it in the table
%with updated values
%extension = '.csv';
%table_filename = strcat(table_filename, extension);
% data = csvread(table_filename,0,0,[0 0 i 17]);
% data = dlmread(table_filename, ',', [0 0 i 12]);
% data = textscan(csvfile, '%s');
% handles.globalmatrix(i,:) = str2double(data{1}{});
% display(data);
% data = transpose(data(:, 2:11));  

try
    raw_data = (Suicide(csvfile, csvfilename, 15))'; 
catch
    
end

%This  raw data is also being transposed.
data = raw_data(2:15,:); %data that will be plotted


%assign row names
Rows = ({'Mission Time','Packet Count','Altitude', 'Pressure','Speed(Pitot)',...
    'Temperature','Voltage','GPS Latitude','GPS Longitude',...
    'GPS Altitude','GPS SatNum','GPS Speed','Cmd Time', 'Cmd Count'});
%update the handles in the table and format
set(handles.uitable1, 'Data', data,...
    'RowName', Rows, 'ColumnName', 'numbered');
% display(handles.Command_Time);

end
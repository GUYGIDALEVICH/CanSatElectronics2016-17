function [] = manual_plot_function(handles)
%   Detailed explanation goes here
csvfile = 1;
value = get(handles.csv_list, 'Value');
file_list = get(handles.csv_list, 'String');
csvfilename = file_list{value};

raw_data = (Manual_Suicide(csvfile, csvfilename, 15))'; 

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

handles.Table_data = get(handles.uitable1,'Data');
n = get(handles.graph1xaxis, 'Value');
k = get(handles.graph1yaxis, 'Value');
handles.x1 = handles.Table_data(n,:);
handles.y1 = handles.Table_data(k,:);
plot(handles.x1, handles.y1,'.','Parent', handles.Graph1);
grid(handles.Graph1, 'on');
end


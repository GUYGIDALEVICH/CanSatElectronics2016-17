function [ard] = ConnectButtonfunc(comport, handles)
%   This file is called when the connect button is clicked on main GUI
%   This file performs the following tasks:
%   1. Open Serial port from comport input variable
%   2. Creates .CSV file and logs all recived telemetery into it at 1Hz
%   3. Outputs csvfile log name for reference
%   4. alsoo outputs timer object for reference
format long;
display ('Connecting ...');
global i;
i=0;
delete (instrfind);
ard = serial(comport);
set (ard, 'DataBits', 8);
set (ard, 'StopBits', 1);
set (ard, 'BaudRate', 19200);
set (ard, 'Parity', 'none');
set (ard, 'InputBufferSize', 1000000);

try %To stop and indicate that Radio is not connected
fopen (ard) %Open Comport
error = false;
catch %if there is an errror in try
error = true; 
msgbox ('No Serial Device on selected COM port, Blafhff'); %Reas the string for info
end

if (error == false)
msgbox ('Serial Connected!!,,yah!');  %Indicate connection ws a sucess  
delete (timerfindall); %Delete all timer objects



csvfilename = datestr(datetime); %Get date and time for name of new file
csvfilename = strrep(csvfilename, ':', '_');
table_filename = csvfilename;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
csvfile = 1; %does nothing simply there for fun

onesecCSVlogger = timer('TimerFcn',{@LTimer_1s, ard, csvfile, csvfilename, handles, table_filename},... 
                        'ExecutionMode','fixedRate','Period', 1); 
%Call csvlogger function every 1 sec period with ard(Serial port) and csvfilelog (name of csv file) as input 
start (onesecCSVlogger);
grid(handles.Graph1, 'on');
end



end


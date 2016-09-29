function [csvfilelog] = ConnectButtonSample('COM3')
%   This file is called when the connect button is clicked on main GUI
%   This file performs the following tasks:
%   1. Open Serial port from comport input variable
%   2. Creates .CSV file and logs all recived telemetery into it at 1Hz
%   3. Outputs csvfile log name for reference
%   4. alsoo outputs timer object for reference

delete (instrfind);
ard = serial('COM3');
set (ard, 'DataBits', 8);
set (ard, 'StopBits', 1);
set (ard, 'BaudRate', 115200);
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
csvfilelog = datetime; %Get date and time for name of new file
csvfile = fopen(csvfilelog, 'a+'); %Open Csv file, only once we need to do this
onesecCSVlogger = timer('TimerFcn',{@csvlogger, ard, csvfilelog},... 
                        'ExecutionMode','fixedRate','Period', 1); 
%Call csvlogger function every 1 sec period with ard(Serial port) and csvfilelog (name of csv file) as input 
end

end











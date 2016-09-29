function [ output_args ] = StopTimerButtonfunc( )
%This function is used to stop all serial logging and timer updates
%Called when StopTimer button is clicked
%Also called when GUI window is closed :) laBalalalala

display ('Stop Timer Button Clicked');
%-----------------
if (numel (timerfindall) ~= 0)
stop (timerfindall); %Stop all timers
delete (timerfindall); %Delete all timer objects
end
%-------------------
if (numel(instrfind) ~= 0)
delete (instrfind); %delete all serial objects
instrreset; %reset device
end
%-------------------
fclose('all'); %Close all open files


end


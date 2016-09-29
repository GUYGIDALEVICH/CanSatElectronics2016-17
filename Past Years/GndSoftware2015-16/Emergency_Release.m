function [] = Emergency_Release(handles)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

handles.Data = get(handles.uitable1,'Data');
Altitude = handles.Data(2,:);
try
Alt_zero = Altitude(2,7);
Actual_Alt = Altitude - Alt_zero;
catch
end

state = 0;
x = Actual_Alt(end) - 550;
x = abs(x);

if x<5 && x>0
    state = state + 1;
end 

if state == 2
global ard;
selectedPort = get(handles.ComportPopup,'Value');
Portlist = get(handles.ComportPopup,'String');
comport = Portlist{selectedPort};
fprintf(comport, '&');
end


end


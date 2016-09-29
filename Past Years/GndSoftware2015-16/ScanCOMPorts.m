function [] = ScanCOMPorts(handles)
%SCANCOMPORTS Summary of this function goes here
%   Detailed explanation goes here

Allportsobj  = instrhwinfo('serial');
Allports = Allportsobj.SerialPorts;
if (numel (Allports) ~= 0)
set (handles.ComportPopup, 'String', Allports);
set (handles.ComportPopup, 'Value', numel (Allports));
else
set (handles.ComportPopup, 'String', 'PORTS EMPTY');
set (handles.ComportPopup, 'Value', 1);
end 


end


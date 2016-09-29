function [] = Update_GUIDateTimeDisplay(handles)
%Updates Date Time dispalay in main GUI
%Notice I passed the handles object from Main GUI
%This Function is called wvwey 1 sec from csv logger.
%looking good.....Enjoy!

spacetime = datestr(datetime); %Get date and time as a astring
spacetime = strrep(spacetime, ':', '_'); %Replaces illegal characters in string
set(handles.DateTimeDisplay, 'String', spacetime); %sets handles to update

end


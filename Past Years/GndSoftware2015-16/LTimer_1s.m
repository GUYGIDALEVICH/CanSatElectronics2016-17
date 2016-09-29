function LTimer_1s(src, evt, ard, csvfile, csvfilename, handles, table_filename)
%%
%   Function performs the following tasks:
%   1. If No new serial data is avilable function does nothing
%   2. if serial data is avilable adds the new data to the .csv file log
%display ('csvlogger');

if (ard.BytesAvailable <= 0) % If no new data
    display ('No New data in Serial port');
else
    %display ('New data is available in Serial port');
    %If new data is avilable
    %csvfile = fopen(csvfilelog, 'a+'); %We only open close and open files once!! in the Connect or disconnect button call back
    csvfile = fopen(strcat (csvfilename,'.csv'), 'a+'); %Open FILE
    StringFromSerial = fscanf(ard, '%s'); %Get new data to string variable
    fprintf ('%s\n',StringFromSerial);
    fprintf(csvfile, strcat(StringFromSerial, '\r\n'));%append string variable to file
    fclose (csvfile);% CLOSE file to allow ather app acess file
    
    %%
    %Update Functions must be below to minimize timer objects
    %This section is called every 1 sec, Therefore plots are updates 1sec
    %'StringFromSeriald' variable contains new lines of serial string from radio
    %So you can use new data to plot..... :)
 try 
    Update_GUIDateTimeDisplay(handles);
    Update_GUItable(handles, table_filename,csvfile, csvfilename);
    Update_GUIgraph(handles, table_filename);
    %Emergency_Release(handles);
 catch exception
     display(exception);
 end 
    
    %%
    
    %fclose(csvfile); %We only open close and open files once!! in the Connect or disconnect button call back  
end 
    %%






end
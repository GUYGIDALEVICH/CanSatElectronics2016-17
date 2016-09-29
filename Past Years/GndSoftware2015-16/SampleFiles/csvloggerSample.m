function csvloggerSample( ard, csvfilelog )
%   Function performs the following tasks:
%   1. If No new serial data is avilable function does nothing
%   2. if serial data is avilable adds the new data to the .csv file log

if (ard.BytesAvailable <= 0) % If no new data
    display ('No New data in Serial port');
else
    %If new data is avilable
    %csvfile = fopen(csvfilelog, 'a+'); %We only open close and open files once!! in the Connect or disconnect button call back
    StringFromSerial = fscanf(ard, '%s'); %Get new data to string variable
    fprintf(csvfile, strcat(StringFromSerial, '\r\n'));%append string variable to file
    %fclose(csvfile); %We only open close and open files once!! in the Connect or disconnect button call back  
end 

end


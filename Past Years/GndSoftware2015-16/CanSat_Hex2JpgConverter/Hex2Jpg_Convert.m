function [ ] = Hex2Jpg_Convert(handles, Hex, file )



display ('Converting Image.');
picfile_hex = fopen(strcat(file, '_HEX.txt'), 'w'); % Verify HEx at http://www.onlinehexeditor.com/
picfile = fopen(strcat(file, '.JPG'), 'w');

count = 1;
fprintf(picfile_hex, '%d-> ', count );
for i=1:2:numel(Hex)-1
    try
    byte_Hex = Hex (i:i+1);
    byte_Num = hex2dec (byte_Hex);
    byte_UniCode = native2unicode(byte_Num);
    
    fprintf(picfile_hex,'%s', byte_Hex);
    fprintf (picfile_hex, ' ');
    
    fprintf(picfile,'%c', byte_UniCode);
    
    if (rem(i, 32) == 31)
        fprintf(picfile_hex, ' -\r\n');
        count = count +1;
        fprintf(picfile_hex, '%d-> ', count );
    end
    
    if (count == 1000)
        fprintf ('.');
    end
    
    catch
   fprintf ('Error in Hex Input. Find: %s\n',Hex (i:i+1));    
    end
    

end




 display ('Done!');
 fclose ('all');
 


end


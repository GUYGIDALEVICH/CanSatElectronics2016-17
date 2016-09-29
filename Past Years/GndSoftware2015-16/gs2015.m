function varargout = gs2015(varargin)
% GS2015 MATLAB code for gs2015.fig
%      GS2015, by itself, creates a new GS2015 or raises the existing
%      singleton*.
%
%      H = GS2015 returns the handle to a new GS2015 or the handle to
%      the existing singleton*.
%
%      GS2015('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GS2015.M with the given input arguments.
%
%      GS2015('Property','Value',...) creates a new GS2015 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before gs2015_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to gs2015_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help gs2015

% Last Modified by GUIDE v2.5 06-Jun-2016 20:08:36

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @gs2015_OpeningFcn, ...
                   'gui_OutputFcn',  @gs2015_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before gs2015 is made visible.
function gs2015_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to gs2015 (see VARARGIN)

% Choose default command line output for gs2015
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes gs2015 wait for user response (see UIRESUME)
% uiwait(handles.figure1);

%Team Tomahawk Logo addition
axes (handles.logo);
imshow ('Team_Tomahawk_logo.JPG');
%CAnada Flag Logo addition
axes (handles.CanadaFlag);
imshow ('CanadaFlag.png');
%populate graph
axes (handles.Graph1);
% Table_data = get(handles.uitable1, 'Data');

guidata(hObject, handles);
%Setup Comport selection popup
ScanCOMPorts(handles);


% --- Outputs from this function are returned to the command line.
function varargout = gs2015_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in popupmenu1.
function popupmenu1_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu1


% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenu2.
function popupmenu2_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu2 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu2


% --- Executes during object creation, after setting all properties.
function popupmenu2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes on selection change in popupmenu4.
function popupmenu4_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu4 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu4

5
% --- Executes during object creation, after setting all properties.
function popupmenu4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in connectbotton.
function connectbotton_Callback(hObject, eventdata, handles)
% hObject    handle to connectbotton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%display (get (handles.comporttext, 'String'));
global ard;
selectedPort = get(handles.ComportPopup,'Value');
Portlist = get(handles.ComportPopup,'String');
comport = Portlist{selectedPort};
ard = ConnectButtonfunc(comport, handles);


% --- Executes on button press in TakePictureButton.
function TakePictureButton_Callback(hObject, eventdata, handles)
% hObject    handle to TakePictureButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global ard;
fprintf(ard, '*');

% --- Executes on button press in NichromeBurnButton.
function NichromeBurnButton_Callback(hObject, eventdata, handles)
% hObject    handle to NichromeBurnButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global ard;
fprintf(ard, '%');


function comporttext_Callback(hObject, eventdata, handles)
% hObject    handle to comporttext (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of comporttext as text
%        str2double(get(hObject,'String')) returns contents of comporttext as a double


% --- Executes during object creation, after setting all properties.
function comporttext_CreateFcn(hObject, eventdata, handles)
% hObject    handle to comporttext (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function servo_angle_Callback(hObject, eventdata, handles)
% hObject    handle to servo_angle (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of servo_angle as text
%        str2double(get(hObject,'String')) returns contents of servo_angle as a double


% --- Executes during object creation, after setting all properties.
function servo_angle_CreateFcn(hObject, eventdata, handles)
% hObject    handle to servo_angle (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


function edit3_Callback(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit3 as text
%        str2double(get(hObject,'String')) returns contents of edit3 as a double



% --- Executes during object creation, after setting all properties.
function edit3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Set_Servo.
function Set_Servo_Callback(hObject, eventdata, handles) 
global ard;
% hObject    handle to Set_Servo (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
angle = get(handles.servo_angle, 'String');
% angle = str2num(angle);
servo_delimeter = '#';
angle = strcat(servo_delimeter, angle);
fprintf(ard, angle);
% ard.BytesAvailableFcnMode = 'byte';
% ard.Terminator = 'CR';
% try
%     ard.BytesAvailable
%     fprintf(ard, angle);
% catch problem
%     display('Problem Caught');
% end 
    


% --- Executes on selection change in graph2xaxis.
function graph2xaxis_Callback(hObject, eventdata, handles)
% hObject    handle to graph2xaxis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



% Hints: contents = cellstr(get(hObject,'String')) returns graph2xaxis contents as cell array
%        contents{get(hObject,'Value')} returns selected item from graph2xaxis
% global ard;
% if (ard.BytesAvailable<= 0);
%  str3 = get(hObject,'String');
%  val3 = get(hObject,'Value');
%  Data = get(handles.uitable1, 'Data');
%  switch str3{val3};
%     case 'Time'
%         handles.graph2xaxis = Data(1,:);
%     case 'Pressure Alt.'
%         handles.graph2xaxis = Data(2,:);
%     case 'Pitot Speed'
%         handles.graph2xaxis = Data(3,:);
%     case 'Temperature'
%         handles.graph2xaxis = Data(4,:);
%     case 'Voltage' 
%         handles.graph2xaxis = Data(5,:);
%     case 'GPS Latitude'
%         handles.graph2xaxis = Data(6,:);
%     case 'GPS Longitude'
%         handles.graph2xaxis = Data(7,:);
%     case 'GPS Altitude'
%         handles.graph2xaxis = Data(8,:);
%     case 'GPS Satnum'
%         handles.graph2xaxis = Data(9,:);
%     case 'GPS Speed'
%         handles.graph2xaxis = Data(10,:);
%  end
%  plot(handles.graph2xaxis, handles.graph2yaxis,'Parent',handles.Graph2);
% end

% --- Executes during object creation, after setting all properties.
function graph2xaxis_CreateFcn(hObject, eventdata, handles)
% hObject    handle to graph2xaxis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in graph2yaxis.
function graph2yaxis_Callback(hObject, eventdata, handles)
% hObject    handle to graph2yaxis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns graph2yaxis contents as cell array
%        contents{get(hObject,'Value')} returns selected item from graph2yaxis
% global ard;
% if (ard.BytesAvailable<= 0);
%  str4 = get(hObject,'String');
%  val4 = get(hObject,'Value');
%  Data = get(handles.uitable1, 'Data');
%  switch str4{val4};
%     case 'Time'
%         handles.graph2yaxis = Data(1,:);
%     case 'Pressure Alt.'
%         handles.graph2yaxis = Data(2,:);
%     case 'Pitot Speed'
%         handles.graph2yaxis = Data(3,:);
%     case 'Temperature'
%         handles.graph2yaxis = Data(4,:);
%     case 'Voltage' 
%         handles.graph2yaxis = Data(5,:);
%     case 'GPS Latitude'
%         handles.graph2yaxis = Data(6,:);
%     case 'GPS Longitude'
%         handles.graph2yaxis = Data(7,:);
%     case 'GPS Altitude'
%         handles.graph2yaxis = Data(8,:);
%     case 'GPS Satnum'
%         handles.graph2yaxis = Data(9,:);
%     case 'GPS Speed'
%         handles.graph2yaxis = Data(10,:);
%  end
%  plot(handles.graph2xaxis, handles.graph2yaxis,'Parent',handles.Graph2);
% end
% --- Executes during object creation, after setting all properties.
function graph2yaxis_CreateFcn(hObject, eventdata, handles)
% hObject    handle to graph2yaxis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes during object creation, after setting all properties.
function edit4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in StopTimer.
function StopTimer_Callback(hObject, eventdata, handles)
% hObject    handle to StopTimer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
StopTimerButtonfunc();

% --- Executes on button press in Help.
function Help_Callback(hObject, eventdata, handles)
% hObject    handle to Help (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
open ('Help.wiki.htm');


% --- Executes on selection change in ComportPopup.
function ComportPopup_Callback(hObject, eventdata, handles)
% hObject    handle to ComportPopup (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns ComportPopup contents as cell array
%        contents{get(hObject,'Value')} returns selected item from ComportPopup
ScanCOMPorts(handles);


% --- Executes during object creation, after setting all properties.
function ComportPopup_CreateFcn(hObject, eventdata, handles)
% hObject    handle to ComportPopup (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on key press with focus on ComportPopup and none of its controls.
function ComportPopup_KeyPressFcn(hObject, eventdata, handles)
% hObject    handle to ComportPopup (see GCBO)
% eventdata  structure with the following fields (see MATLAB.UI.CONTROL.UICONTROL)
%	Key: name of the key that was pressed, in lower case
%	Character: character interpretation of the key(s) that was pressed
%	Modifier: name(s) of the modifier key(s) (i.e., control, shift) pressed
% handles    structure with handles and user data (see GUIDATA)
ScanCOMPorts(handles);


% --------------------------------------------------------------------
function uipanel2_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to uipanel2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
ScanCOMPorts(handles);
Scan_csv_Files(handles);


% --- Executes during object deletion, before destroying properties.
function figure1_DeleteFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
StopTimerButtonfunc();



function Note1_Callback(hObject, eventdata, handles)
% hObject    handle to Note1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Note1 as text
%        str2double(get(hObject,'String')) returns contents of Note1 as a double


% --- Executes during object creation, after setting all properties.
function Note1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Note1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes when entered data in editable cell(s) in uitable1.
function uitable1_CellEditCallback(hObject, eventdata, handles)
% hObject    handle to uitable1 (see GCBO)
% eventdata  structure with the following fields (see MATLAB.UI.CONTROL.TABLE)
%	Indices: row and column indices of the cell(s) edited
%	PreviousData: previous data for the cell(s) edited
%	EditData: string(s) entered by the user
%	NewData: EditData or its converted form set on the Data property. Empty if Data was not changed
%	Error: error string when failed to convert EditData to appropriate value for Data
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object creation, after setting all properties.
function Graph1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Graph1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
% Hint: place code in OpeningFcn to populate Graph1
handles.Graph1=hObject; % tag for this axis, which I call axesX in this example
guidata(hObject, handles); % update the handles structure for the gui

% --- Executes during object creation, after setting all properties.
function Graph2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Graph2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
% Hint: place code in OpeningFcn to populate Graph2
handles.Graph2=hObject; % tag for this axis, which I call axesX in this example
guidata(hObject, handles); % update the handles structure for the gui


% --- Executes when selected cell(s) is changed in uitable1.
function uitable1_CellSelectionCallback(hObject, eventdata, handles)
% hObject    handle to uitable1 (see GCBO)
% eventdata  structure with the following fields (see MATLAB.UI.CONTROL.TABLE)
%	Indices: row and column indices of the cell(s) currently selecteds
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on selection change in graph1xaxis.
function graph1xaxis_Callback(hObject, eventdata, handles)
% hObject    handle to graph1xaxis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

 

% Hints: contents = cellstr(get(hObject,'String')) returns graph1xaxis contents as cell array
%        contents{get(hObject,'Value')} returns selected item from graph1xaxis
% global ard;
% if (ard.BytesAvailable<= 0);
%  str1 = get(hObject,'String');
%  val1 = get(hObject,'Value');
%  Data = get(handles.uitable1, 'Data');
%  switch str1{val1};
%     case 'Time'
%         handles.graph1xaxis = Data(1,:);
%     case 'Pressure Alt.'
%         handles.graph1xaxis = Data(2,:);
%     case 'Pitot Speed'
%         handles.graph1xaxis = Data(3,:);
%     case 'Temperature'
%         handles.graph1xaxis = Data(4,:);
%     case 'Voltage' 
%         handles.graph1xaxis = Data(5,:);
%     case 'GPS Latitude'
%         handles.graph1xaxis = Data(6,:);
%     case 'GPS Longitude'
%         handles.graph1xaxis = Data(7,:);
%     case 'GPS Altitude'
%         handles.graph1xaxis = Data(8,:);
%     case 'GPS Satnum'
%         handles.graph1xaxis = Data(9,:);
%     case 'GPS Speed'
%         handles.graph1xaxis = Data(10,:);
%  end
%  end
% --- Executes during object creation, after setting all properties.
function graph1xaxis_CreateFcn(hObject, eventdata, handles)
% hObject    handle to graph1xaxis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in graph1yaxis.
function graph1yaxis_Callback(hObject, eventdata, handles)
% hObject    handle to graph1yaxis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns graph1yaxis contents as cell array
%        contents{get(hObject,'Value')} returns selected item from graph1yaxis
% global ard;
% if (ard.BytesAvailable <= 0);
%  str2 = get(hObject,'String');
%  val2 = get(hObject,'Value');
%  Data = get(handles.uitable1, 'Data');
%  switch str2{val2};
%     case 'Time'
%         handles.graph1yaxis = Data(1,:);
%     case 'Pressure Alt.'
%         handles.graph1yaxis = Data(2,:);
%     case 'Pitot Speed'
%         handles.graph1yaxis = Data(3,:);
%     case 'Temperature'
%         handles.graph1yaxis = Data(4,:);
%     case 'Voltage' 
%         handles.graph1yaxis = Data(5,:);
%     case 'GPS Latitude'
%         handles.graph1yaxis = Data(6,:);
%     case 'GPS Longitude'
%         handles.graph1yaxis = Data(7,:);
%     case 'GPS Altitude'
%         handles.graph1yaxis = Data(8,:);
%     case 'GPS Satnum'
%         handles.graph1yaxis = Data(9,:);
%     case 'GPS Speed'
%         handles.graph1yaxis = Data(10,:);
%  end
%  plot(handles.graph1xaxis, handles.graph1yaxis,'Parent',handles.Graph1);
% end

% --- Executes during object creation, after setting all properties.
function graph1yaxis_CreateFcn(hObject, eventdata, handles)
% hObject    handle to graph1yaxis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Plot_from_File.
function Plot_from_File_Callback(hObject, eventdata, handles)
% hObject    handle to Plot_from_File (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
manual_plot_function(handles);


% --- Executes on selection change in csv_list.
function csv_list_Callback(hObject, eventdata, handles)
% hObject    handle to csv_list (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Scan_csv_Files(handles);
% Hints: contents = cellstr(get(hObject,'String')) returns csv_list contents as cell array
%        contents{get(hObject,'Value')} returns selected item from csv_list


% --- Executes during object creation, after setting all properties.
function csv_list_CreateFcn(hObject, eventdata, handles)
% hObject    handle to csv_list (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in LatestImage.
function LatestImage_Callback(hObject, eventdata, handles)
% hObject    handle to LatestImage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global ard;
fprintf(ard, '+');

% --- Executes on button press in Buzz.
function Buzz_Callback(hObject, eventdata, handles)
% hObject    handle to Buzz (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global ard;
fprintf(ard, '@');

function varargout = CHex2Jpg_Converter(varargin)
% CHEX2JPG_CONVERTER MATLAB code for CHex2Jpg_Converter.fig
%      CHEX2JPG_CONVERTER, by itself, creates a new CHEX2JPG_CONVERTER or raises the existing
%      singleton*.
%
%      H = CHEX2JPG_CONVERTER returns the handle to a new CHEX2JPG_CONVERTER or the handle to
%      the existing singleton*.
%
%      CHEX2JPG_CONVERTER('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in CHEX2JPG_CONVERTER.M with the given input arguments.
%
%      CHEX2JPG_CONVERTER('Property','Value',...) creates a new CHEX2JPG_CONVERTER or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before CHex2Jpg_Converter_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to CHex2Jpg_Converter_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help CHex2Jpg_Converter

% Last Modified by GUIDE v2.5 11-Jun-2016 00:35:36

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @CHex2Jpg_Converter_OpeningFcn, ...
                   'gui_OutputFcn',  @CHex2Jpg_Converter_OutputFcn, ...
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


% --- Executes just before CHex2Jpg_Converter is made visible.
function CHex2Jpg_Converter_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to CHex2Jpg_Converter (see VARARGIN)

% Choose default command line output for CHex2Jpg_Converter
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);


axes (handles.logo);
imshow ('Team_Tomahawk_logo.JPG');
axes (handles.Image);
imshow ('Team_Tomahawk_logo.JPG');

% UIWAIT makes CHex2Jpg_Converter wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this functionare returned to the command line.
function varargout = CHex2Jpg_Converter_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} =handles.output;


% --- Executes on button press in Convert_Button.
function Convert_Button_Callback(hObject, eventdata, handles)
% hObject    handle to Convert_Button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

gocolor = get (handles.Convert_Button, 'BackgroundColor');
set (handles.Convert_Button, 'String', 'Busy...');
set (handles.Convert_Button, 'BackgroundColor', 'red');
pause (0.5);

Hex2Jpg_Convert(handles, get (handles.HexData, 'String'), get(handles.ImagefileName, 'String'));
axes (handles.Image);
show = strcat(get(handles.ImagefileName, 'String'), '.JPG');
imshow (show);


 set (handles.Convert_Button, 'BackgroundColor', gocolor);
 set (handles.Convert_Button, 'String', 'Convert');

function HexData_Callback(hObject, eventdata, handles)
% hObject    handle to HexData (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of HexData as text
%        str2double(get(hObject,'String')) returns contents of HexData as a double


% --- Executes during object creation, after setting all properties.
function HexData_CreateFcn(hObject, eventdata, handles)
% hObject    handle to HexData (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function ImagefileName_Callback(hObject, eventdata, handles)
% hObject    handle to ImagefileName (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of ImagefileName as text
%        str2double(get(hObject,'String')) returns contents of ImagefileName as a double


% --- Executes during object creation, after setting all properties.
function ImagefileName_CreateFcn(hObject, eventdata, handles)
% hObject    handle to ImagefileName (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Help.
function Help_Callback(hObject, eventdata, handles)
% hObject    handle to Help (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function csv_filename_Callback(hObject, eventdata, handles)
% hObject    handle to csv_filename (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of csv_filename as text
%        str2double(get(hObject,'String')) returns contents of csv_filename as a double


% --- Executes during object creation, after setting all properties.
function csv_filename_CreateFcn(hObject, eventdata, handles)
% hObject    handle to csv_filename (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Fill_hex_field.
function Fill_hex_field_Callback(hObject, eventdata, handles)
% hObject    handle to Fill_hex_field (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
csv_name = get(handles.csv_filename, 'String');
convert_me = sprintf(Suicide(1, csv_name, 15, handles));
id = fopen('hex_data.txt');
line = fscanf(id, '%s');
set(handles.HexData, 'String', line);



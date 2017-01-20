///////////////////////////////////////////////////////////////////////
//                         Instructions                              //
///////////////////////////////////////////////////////////////////////

//Writing Float Array to External EEPROM
//extEEPROMWrite(Address of Array, Number of Values)

//Reading All of External EERPOM
//extEEPROMRead()

//Writing Float to Internal EEPEOM
//EEPROM.put(Address, Variable)

//Reading Float from Internal EEPROM
//EEPROM.get(Address, Variable to store value in)



///////////////////////////////////////////////////////////////////////
//                 Writing Float Arrays to EEPROM                    //
///////////////////////////////////////////////////////////////////////

void extEEPROMRead(long numValues) {
  float value;
  long eeAddress_R = 0;
  //long numValues = 64000; //256000 / sizeof(float)
  for (long i = 0; i < numValues; i++) {
    if (eeAddress_R + sizeof(float) >= 256000) {
      eeAddress_R = 0;
    }
    EEPROM_readAnything(eeAddress_R, value);
    if (value == (float) - 888.0) {
      Serial.print("\n");
    } else {
      Serial.print(value, DEC);
      Serial.print(",");
    }
    eeAddress_R += sizeof(float);
  }
}

void extEEPROMWrite(int data[], int dataSize) {
  for (int i = 0; i < dataSize; i++) {
    if (eeAddress_W + sizeof(int) >= 256000) {
      eeAddress_W = 0;
    }
    Serial.println("1");
    EEPROM_writeAnything(eeAddress_W, data[i]);
    Serial.println("2");
    eeAddress_W += sizeof(int);
  }

  //Stores current ext EEPROM location in the internal eeprom
 
}

///////////////////////////////////////////////////////////////////////
//                 Writing Variables to EEPROM                       //
///////////////////////////////////////////////////////////////////////


template <class T> int EEPROM_writeAnything(int ee, const T& value)
{
  const byte* p = (const byte*)(const void*)&value;
  unsigned int i;
  for (i = 0; i < sizeof(value); i++)
    EXTwriteEEPROM_byte(EEPROM_ID, ee++, *p++);
  return i;
}

template <class T> int EEPROM_readAnything(int ee, T& value)
{
  byte* p = (byte*)(void*)&value;
  unsigned int i;
  for (i = 0; i < sizeof(value); i++)
    *p++ = EXTreadEEPROM_byte(EEPROM_ID, ee++);
  return i;
}


///////////////////////////////////////////////////////////////////////
//                 Writing Bytes to EEPROM                           //
///////////////////////////////////////////////////////////////////////


void EXTwriteEEPROM_byte(int deviceaddress, unsigned int eeaddress, byte data )
{
  Serial.println("3");
  Wire.beginTransmission(deviceaddress);
  
  Wire.write((int)(eeaddress >> 8));
  Wire.write((int)(eeaddress & 0xFF));
  Wire.write(data);
  Serial.println("4"); 
  Wire.endTransmission();
 Serial.println("5"); 
  delay(5);
}

byte EXTreadEEPROM_byte(int deviceaddress, unsigned int eeaddress )
{
  byte rdata = 0xFF;

  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddress >> 8));
  Wire.write((int)(eeaddress & 0xFF));
  Wire.endTransmission();

  Wire.requestFrom(deviceaddress, 1);

  if (Wire.available()) rdata = Wire.read();

  return rdata;
}

///////////////////////////////////////////////////////////////////////////////
//Internal EEPROM Saving
template <class T> int intEEPROM_writeAnything(int ee, const T& value)
{
    const byte* p = (const byte*)(const void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          EEPROM.write(ee++, *p++);
    return i;
}

template <class T> int intEEPROM_readAnything(int ee, T& value)
{
    byte* p = (byte*)(void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          *p++ = EEPROM.read(ee++);
    return i;
}





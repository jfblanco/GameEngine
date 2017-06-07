#ifndef __ENGINE__IMPORTER_FBXIMPORTER_BYNARY_PROPERTY_
#define __ENGINE__IMPORTER_FBXIMPORTER_BYNARY_PROPERTY_

  class BinaryProperty{
  private:
    char* typeCode;
    short* data;
    unsigned long length = 1;
    unsigned long arrayEncoding;
    unsigned long arrayCompressedLength;

  public:
    BinaryProperty();
    ~BinaryProperty();
    void setTypeCode(char*);
    void setPrimitiveData(char*, long);
    bool isArray();
    bool isPrimitive();
    long getDataLength();
    unsigned long getArrayLength();
    void setArrayMetaData(char*);
    void setArrayData(char*);
    unsigned long getObjectLength();
    void setObjectMetaData(char*);
    void setObjectData(char*);
    void printProperty();
  };
#endif

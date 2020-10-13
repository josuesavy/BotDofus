#ifndef SIMPLECHARACTERCHARACTERISTICFORPRESET_H
#define SIMPLECHARACTERCHARACTERISTICFORPRESET_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class SimpleCharacterCharacteristicForPreset : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SimpleCharacterCharacteristicForPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SimpleCharacterCharacteristicForPreset(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SimpleCharacterCharacteristicForPreset(FuncTree tree);
  SimpleCharacterCharacteristicForPreset();
  bool operator==(const SimpleCharacterCharacteristicForPreset &compared);

  QString keyword;
  int base;
  int additionnal;

private:
  void _keywordFunc(Reader *input);
  void _baseFunc(Reader *input);
  void _additionnalFunc(Reader *input);
};

#endif // SIMPLECHARACTERCHARACTERISTICFORPRESET_H
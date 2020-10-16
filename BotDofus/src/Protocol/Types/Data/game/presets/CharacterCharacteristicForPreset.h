#ifndef CHARACTERCHARACTERISTICFORPRESET_H
#define CHARACTERCHARACTERISTICFORPRESET_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/presets/SimpleCharacterCharacteristicForPreset.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class CharacterCharacteristicForPreset : public SimpleCharacterCharacteristicForPreset
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterCharacteristicForPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterCharacteristicForPreset(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterCharacteristicForPreset(FuncTree tree);
  CharacterCharacteristicForPreset();
  bool operator==(const CharacterCharacteristicForPreset &compared);

  int stuff;

private:
  void _stuffFunc(Reader *input);
};

#endif // CHARACTERCHARACTERISTICFORPRESET_H
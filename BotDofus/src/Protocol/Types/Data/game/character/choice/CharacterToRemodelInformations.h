#ifndef CHARACTERTOREMODELINFORMATIONS_H
#define CHARACTERTOREMODELINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/choice/CharacterRemodelingInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class CharacterToRemodelInformations : public CharacterRemodelingInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterToRemodelInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterToRemodelInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterToRemodelInformations(FuncTree tree);
  CharacterToRemodelInformations();
  bool operator==(const CharacterToRemodelInformations &compared);

  uint possibleChangeMask;
  uint mandatoryChangeMask;

private:
  void _possibleChangeMaskFunc(Reader *input);
  void _mandatoryChangeMaskFunc(Reader *input);
};

#endif // CHARACTERTOREMODELINFORMATIONS_H
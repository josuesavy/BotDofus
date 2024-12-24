#ifndef CHARACTERBASICMINIMALINFORMATIONS_H
#define CHARACTERBASICMINIMALINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/character/AbstractCharacterInformation.h"
#include "src/utils/io/type/FuncTree.h"

class CharacterBasicMinimalInformations : public AbstractCharacterInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterBasicMinimalInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterBasicMinimalInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterBasicMinimalInformations(FuncTree tree);
  CharacterBasicMinimalInformations();
  bool operator==(const CharacterBasicMinimalInformations &compared);

  QString name;

private:
  void _nameFunc(Reader *input);
};

#endif // CHARACTERBASICMINIMALINFORMATIONS_H
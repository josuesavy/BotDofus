#ifndef CHARACTERREMODELINGINFORMATION_H
#define CHARACTERREMODELINGINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/character/AbstractCharacterInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class CharacterRemodelingInformation : public AbstractCharacterInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterRemodelingInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterRemodelingInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterRemodelingInformation(FuncTree tree);
  CharacterRemodelingInformation();
  bool operator==(const CharacterRemodelingInformation &compared);

  QString name;
  int breed;
  bool sex;
  uint cosmeticId;
  QList<int> colors;

private:
  void _nameFunc(Reader *input);
  void _breedFunc(Reader *input);
  void _sexFunc(Reader *input);
  void _cosmeticIdFunc(Reader *input);
  void _colorstreeFunc(Reader *input);
  void _colorsFunc(Reader *input);

  FuncTree _colorstree;
};

#endif // CHARACTERREMODELINGINFORMATION_H
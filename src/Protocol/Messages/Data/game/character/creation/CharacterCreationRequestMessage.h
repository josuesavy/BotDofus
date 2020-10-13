#ifndef CHARACTERCREATIONREQUESTMESSAGE_H
#define CHARACTERCREATIONREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Enums/Data/PlayableBreedEnum.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class CharacterCreationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterCreationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterCreationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterCreationRequestMessage(FuncTree tree);
  CharacterCreationRequestMessage();

  QString name;
  int breed;
  bool sex;
  QList<int> colors;
  uint cosmeticId;

private:
  void _nameFunc(Reader *input);
  void _breedFunc(Reader *input);
  void _sexFunc(Reader *input);
  void _colorstreeFunc(Reader *input);
  void _colorsFunc(Reader *input);
  void _cosmeticIdFunc(Reader *input);

  FuncTree _colorstree;
  uint _colorsindex;
};

#endif // CHARACTERCREATIONREQUESTMESSAGE_H
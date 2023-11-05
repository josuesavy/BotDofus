#ifndef CHARACTERCHARACTERISTICS_H
#define CHARACTERCHARACTERISTICS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class CharacterCharacteristics : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterCharacteristics(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterCharacteristics(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterCharacteristics(FuncTree tree);
  CharacterCharacteristics();
  bool operator==(const CharacterCharacteristics &compared);

  QList<> characteristics;

private:
  void _characteristicstreeFunc(Reader *input);
  void _characteristicsFunc(Reader *input);

  FuncTree _characteristicstree;
};

#endif // CHARACTERCHARACTERISTICS_H
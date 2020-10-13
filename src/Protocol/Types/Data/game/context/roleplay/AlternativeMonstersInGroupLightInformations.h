#ifndef ALTERNATIVEMONSTERSINGROUPLIGHTINFORMATIONS_H
#define ALTERNATIVEMONSTERSINGROUPLIGHTINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/MonsterInGroupLightInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class AlternativeMonstersInGroupLightInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlternativeMonstersInGroupLightInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlternativeMonstersInGroupLightInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlternativeMonstersInGroupLightInformations(FuncTree tree);
  AlternativeMonstersInGroupLightInformations();
  bool operator==(const AlternativeMonstersInGroupLightInformations &compared);

  int playerCount;
  QList<MonsterInGroupLightInformations> monsters;

private:
  void _playerCountFunc(Reader *input);
  void _monsterstreeFunc(Reader *input);
  void _monstersFunc(Reader *input);

  FuncTree _monsterstree;
};

#endif // ALTERNATIVEMONSTERSINGROUPLIGHTINFORMATIONS_H
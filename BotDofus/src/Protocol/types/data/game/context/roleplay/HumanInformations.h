#ifndef HUMANINFORMATIONS_H
#define HUMANINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/restriction/ActorRestrictionsInformations.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOption.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class HumanInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HumanInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HumanInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HumanInformations(FuncTree tree);
  HumanInformations();
  bool operator==(const HumanInformations &compared);

  ActorRestrictionsInformations restrictions;
  bool sex;
  QList<QSharedPointer<HumanOption>> options;

private:
  void _restrictionstreeFunc(Reader *input);
  void _sexFunc(Reader *input);
  void _optionstreeFunc(Reader *input);
  void _optionsFunc(Reader *input);

  FuncTree _restrictionstree;
  FuncTree _optionstree;
};

#endif // HUMANINFORMATIONS_H
#ifndef HUMANINFORMATIONS_H
#define HUMANINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/character/restriction/ActorRestrictionsInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOption.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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
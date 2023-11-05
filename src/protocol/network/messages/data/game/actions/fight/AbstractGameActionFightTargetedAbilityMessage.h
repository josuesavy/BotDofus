#ifndef ABSTRACTGAMEACTIONFIGHTTARGETEDABILITYMESSAGE_H
#define ABSTRACTGAMEACTIONFIGHTTARGETEDABILITYMESSAGE_H

#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/actions/AbstractGameActionMessage.h"

class AbstractGameActionFightTargetedAbilityMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AbstractGameActionFightTargetedAbilityMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AbstractGameActionFightTargetedAbilityMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AbstractGameActionFightTargetedAbilityMessage(FuncTree tree);
  AbstractGameActionFightTargetedAbilityMessage();

  double targetId;
  int destinationCellId;
  uint critical;
  bool silentCast;
  bool verboseCast;

private:
  void deserializeByteBoxes(Reader *input);
  void _targetIdFunc(Reader *input);
  void _destinationCellIdFunc(Reader *input);
  void _criticalFunc(Reader *input);
};

#endif // ABSTRACTGAMEACTIONFIGHTTARGETEDABILITYMESSAGE_H
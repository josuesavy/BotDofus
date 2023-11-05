#ifndef BREACHBRANCHESMESSAGE_H
#define BREACHBRANCHESMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/game/context/roleplay/breach/ExtendedBreachBranch.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class BreachBranchesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachBranchesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachBranchesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachBranchesMessage(FuncTree tree);
  BreachBranchesMessage();

  QList<QSharedPointer<ExtendedBreachBranch>> branches;

private:
  void _branchestreeFunc(Reader *input);
  void _branchesFunc(Reader *input);

  FuncTree _branchestree;
};

#endif // BREACHBRANCHESMESSAGE_H
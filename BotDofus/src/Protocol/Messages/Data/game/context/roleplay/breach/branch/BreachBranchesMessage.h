#ifndef BREACHBRANCHESMESSAGE_H
#define BREACHBRANCHESMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/breach/ExtendedBreachBranch.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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
#ifndef CHALLENGETARGETSLISTMESSAGE_H
#define CHALLENGETARGETSLISTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ChallengeTargetsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeTargetsListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeTargetsListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeTargetsListMessage(FuncTree tree);
  ChallengeTargetsListMessage();

  QList<double> targetIds;
  QList<int> targetCells;

private:
  void _targetIdstreeFunc(Reader *input);
  void _targetIdsFunc(Reader *input);
  void _targetCellstreeFunc(Reader *input);
  void _targetCellsFunc(Reader *input);

  FuncTree _targetIdstree;
  FuncTree _targetCellstree;
};

#endif // CHALLENGETARGETSLISTMESSAGE_H
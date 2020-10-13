#ifndef TREASUREHUNTMESSAGE_H
#define TREASUREHUNTMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "src/Protocol/Types/Data/game/context/roleplay/treasureHunt/TreasureHuntFlag.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TreasureHuntMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntMessage(FuncTree tree);
  TreasureHuntMessage();

  uint questType;
  double startMapId;
  QList<QSharedPointer<TreasureHuntStep>> knownStepsList;
  uint totalStepCount;
  uint checkPointCurrent;
  uint checkPointTotal;
  int availableRetryCount;
  QList<TreasureHuntFlag> flags;

private:
  void _questTypeFunc(Reader *input);
  void _startMapIdFunc(Reader *input);
  void _knownStepsListtreeFunc(Reader *input);
  void _knownStepsListFunc(Reader *input);
  void _totalStepCountFunc(Reader *input);
  void _checkPointCurrentFunc(Reader *input);
  void _checkPointTotalFunc(Reader *input);
  void _availableRetryCountFunc(Reader *input);
  void _flagstreeFunc(Reader *input);
  void _flagsFunc(Reader *input);

  FuncTree _knownStepsListtree;
  FuncTree _flagstree;
};

#endif // TREASUREHUNTMESSAGE_H
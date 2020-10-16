#ifndef FIGHTSTARTINGPOSITIONS_H
#define FIGHTSTARTINGPOSITIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FightStartingPositions : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightStartingPositions(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightStartingPositions(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightStartingPositions(FuncTree tree);
  FightStartingPositions();
  bool operator==(const FightStartingPositions &compared);

  QList<uint> positionsForChallengers;
  QList<uint> positionsForDefenders;

private:
  void _positionsForChallengerstreeFunc(Reader *input);
  void _positionsForChallengersFunc(Reader *input);
  void _positionsForDefenderstreeFunc(Reader *input);
  void _positionsForDefendersFunc(Reader *input);

  FuncTree _positionsForChallengerstree;
  FuncTree _positionsForDefenderstree;
};

#endif // FIGHTSTARTINGPOSITIONS_H
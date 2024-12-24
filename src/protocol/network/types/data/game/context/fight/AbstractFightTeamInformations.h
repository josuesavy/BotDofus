#ifndef ABSTRACTFIGHTTEAMINFORMATIONS_H
#define ABSTRACTFIGHTTEAMINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class AbstractFightTeamInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AbstractFightTeamInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AbstractFightTeamInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AbstractFightTeamInformations(FuncTree tree);
  AbstractFightTeamInformations();
  bool operator==(const AbstractFightTeamInformations &compared);

  uint teamId;
  double leaderId;
  int teamSide;
  uint teamTypeId;
  uint nbWaves;

private:
  void _teamIdFunc(Reader *input);
  void _leaderIdFunc(Reader *input);
  void _teamSideFunc(Reader *input);
  void _teamTypeIdFunc(Reader *input);
  void _nbWavesFunc(Reader *input);
};

#endif // ABSTRACTFIGHTTEAMINFORMATIONS_H
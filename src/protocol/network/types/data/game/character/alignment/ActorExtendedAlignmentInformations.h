#ifndef ACTOREXTENDEDALIGNMENTINFORMATIONS_H
#define ACTOREXTENDEDALIGNMENTINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/character/alignment/ActorAlignmentInformations.h"
#include "src/utils/io/type/FuncTree.h"

class ActorExtendedAlignmentInformations : public ActorAlignmentInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ActorExtendedAlignmentInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ActorExtendedAlignmentInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ActorExtendedAlignmentInformations(FuncTree tree);
  ActorExtendedAlignmentInformations();
  bool operator==(const ActorExtendedAlignmentInformations &compared);

  uint honor;
  uint honorGradeFloor;
  uint honorNextGradeFloor;
  uint aggressable;

private:
  void _honorFunc(Reader *input);
  void _honorGradeFloorFunc(Reader *input);
  void _honorNextGradeFloorFunc(Reader *input);
  void _aggressableFunc(Reader *input);
};

#endif // ACTOREXTENDEDALIGNMENTINFORMATIONS_H
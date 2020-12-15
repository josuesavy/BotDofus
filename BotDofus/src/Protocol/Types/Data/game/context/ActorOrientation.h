#ifndef ACTORORIENTATION_H
#define ACTORORIENTATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ActorOrientation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ActorOrientation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ActorOrientation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ActorOrientation(FuncTree tree);
  ActorOrientation();
  bool operator==(const ActorOrientation &compared);

  double id;
  uint direction;

private:
  void _idFunc(Reader *input);
  void _directionFunc(Reader *input);
};

#endif // ACTORORIENTATION_H
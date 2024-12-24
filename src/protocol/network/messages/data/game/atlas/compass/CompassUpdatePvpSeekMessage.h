#ifndef COMPASSUPDATEPVPSEEKMESSAGE_H
#define COMPASSUPDATEPVPSEEKMESSAGE_H

#include "src/protocol/network/types/data/game/context/MapCoordinates.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/atlas/compass/CompassUpdateMessage.h"

class CompassUpdatePvpSeekMessage : public CompassUpdateMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CompassUpdatePvpSeekMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CompassUpdatePvpSeekMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CompassUpdatePvpSeekMessage(FuncTree tree);
  CompassUpdatePvpSeekMessage();

  double memberId;
  QString memberName;

private:
  void _memberIdFunc(Reader *input);
  void _memberNameFunc(Reader *input);
};

#endif // COMPASSUPDATEPVPSEEKMESSAGE_H
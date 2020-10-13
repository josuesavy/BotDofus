#ifndef GAMEFIGHTTURNLISTMESSAGE_H
#define GAMEFIGHTTURNLISTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameFightTurnListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightTurnListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightTurnListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightTurnListMessage(FuncTree tree);
  GameFightTurnListMessage();

  QList<double> ids;
  QList<double> deadsIds;

private:
  void _idstreeFunc(Reader *input);
  void _idsFunc(Reader *input);
  void _deadsIdstreeFunc(Reader *input);
  void _deadsIdsFunc(Reader *input);

  FuncTree _idstree;
  FuncTree _deadsIdstree;
};

#endif // GAMEFIGHTTURNLISTMESSAGE_H
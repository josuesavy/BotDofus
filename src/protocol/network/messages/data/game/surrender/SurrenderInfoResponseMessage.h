#ifndef SURRENDERINFORESPONSEMESSAGE_H
#define SURRENDERINFORESPONSEMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/surrender/SurrenderResponse.h"
#include "src/protocol/network/types/data/game/surrender/vote/SurrenderVoteResponse.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SurrenderInfoResponseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderInfoResponseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderInfoResponseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderInfoResponseMessage(FuncTree tree);
  SurrenderInfoResponseMessage();

  bool hasSanction;
  QSharedPointer<SurrenderResponse> surrenderResponse;
  QSharedPointer<SurrenderVoteResponse> surrenderVoteResponse;

private:
  void _hasSanctionFunc(Reader *input);
  void _surrenderResponsetreeFunc(Reader *input);
  void _surrenderVoteResponsetreeFunc(Reader *input);

  FuncTree _surrenderResponsetree;
  FuncTree _surrenderVoteResponsetree;
};

#endif // SURRENDERINFORESPONSEMESSAGE_H
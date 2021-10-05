#ifndef SERVERSESSIONCONSTANTLONG_H
#define SERVERSESSIONCONSTANTLONG_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/approach/ServerSessionConstant.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ServerSessionConstantLong : public ServerSessionConstant
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ServerSessionConstantLong(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ServerSessionConstantLong(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ServerSessionConstantLong(FuncTree tree);
  ServerSessionConstantLong();
  bool operator==(const ServerSessionConstantLong &compared);

  double value;

private:
  void _valueFunc(Reader *input);
};

#endif // SERVERSESSIONCONSTANTLONG_H
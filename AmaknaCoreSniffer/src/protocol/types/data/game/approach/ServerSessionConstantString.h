#ifndef SERVERSESSIONCONSTANTSTRING_H
#define SERVERSESSIONCONSTANTSTRING_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/approach/ServerSessionConstant.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ServerSessionConstantString : public ServerSessionConstant
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ServerSessionConstantString(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ServerSessionConstantString(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ServerSessionConstantString(FuncTree tree);
  ServerSessionConstantString();
  bool operator==(const ServerSessionConstantString &compared);

  QString value;

private:
  void _valueFunc(Reader *input);
};

#endif // SERVERSESSIONCONSTANTSTRING_H
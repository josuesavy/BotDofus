#ifndef SERVERSESSIONCONSTANTSTRING_H
#define SERVERSESSIONCONSTANTSTRING_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/approach/ServerSessionConstant.h"
#include "src/utils/io/type/FuncTree.h"

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
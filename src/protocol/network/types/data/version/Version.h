#ifndef VERSION_H
#define VERSION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class Version : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_Version(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_Version(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_Version(FuncTree tree);
  Version();
  bool operator==(const Version &compared);

  uint major;
  uint minor;
  uint code;
  uint build;
  uint buildType;

private:
  void _majorFunc(Reader *input);
  void _minorFunc(Reader *input);
  void _codeFunc(Reader *input);
  void _buildFunc(Reader *input);
  void _buildTypeFunc(Reader *input);
};

#endif // VERSION_H
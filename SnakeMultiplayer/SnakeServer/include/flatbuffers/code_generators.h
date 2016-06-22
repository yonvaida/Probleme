/*
 * Copyright 2014 Google Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FLATBUFFERS_CODE_GENERATORS_H_
#define FLATBUFFERS_CODE_GENERATORS_H_

namespace flatbuffers {

class BaseGenerator {
 public:
  virtual bool generate() = 0;

  static const std::string NamespaceDir(const Parser &parser,
                                        const std::string &path,
                                        const Namespace &ns) {
    EnsureDirExists(path.c_str());
    if (parser.opts.one_file) return path;
    std::string namespace_dir = path;  // Either empty or ends in separator.
    auto &namespaces = ns.components;
    for (auto it = namespaces.begin(); it != namespaces.end(); ++it) {
      namespace_dir += *it + kPathSeparator;
      EnsureDirExists(namespace_dir.c_str());
    }
    return namespace_dir;
  }

 protected:
  BaseGenerator(const Parser &parser, const std::string &path,
                const std::string &file_name)
      : parser_(parser),
        path_(path),
        file_name_(file_name) {};
  virtual ~BaseGenerator() {};

  // No copy/assign.
  BaseGenerator &operator=(const BaseGenerator &);
  BaseGenerator(const BaseGenerator &);

  const std::string NamespaceDir(const Namespace &ns) {
    return BaseGenerator::NamespaceDir(parser_, path_, ns);
  }

  const char *FlatBuffersGeneratedWarning() {
    return "automatically generated by the FlatBuffers compiler,"
           " do not modify\n\n";
  }

  bool IsEverythingGenerated() {
    for (auto it = parser_.enums_.vec.begin(); it != parser_.enums_.vec.end();
         ++it) {
      if (!(*it)->generated) return false;
    }
    for (auto it = parser_.structs_.vec.begin();
         it != parser_.structs_.vec.end(); ++it) {
      if (!(*it)->generated) return false;
    }
    return true;
  }

  std::string FullNamespace(const char *separator, const Namespace &ns) {
    std::string namespace_name;
    auto &namespaces = ns.components;
    for (auto it = namespaces.begin(); it != namespaces.end(); ++it) {
      if (namespace_name.length()) namespace_name += separator;
      namespace_name += *it;
    }
    return namespace_name;
  }

  const std::string LastNamespacePart(const Namespace &ns) {
    auto &namespaces = ns.components;
    if (namespaces.size()) return *(namespaces.end() - 1); else return std::string("");
  }

  const Parser &parser_;
  const std::string &path_;
  const std::string &file_name_;
};

}  // namespace flatbuffers

#endif  // FLATBUFFERS_CODE_GENERATORS_H_

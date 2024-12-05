modules+=hello

hello: $(wildcard $(modules_dir)/hello/*.cpp)
	@echo "开始编译模块: "$@
	$(CXX) -c $^ -o $(output_dir)/$@.o
	@echo $@"编译完成"

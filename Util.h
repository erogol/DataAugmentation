/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                           License Agreement
//
// Copyright (C) 2014 Takuya MINAGAWA.
// Third party copyrights are property of their respective owners.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do
// so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//M*/

#ifndef __UTIL__
#define __UTIL__

#include <opencv2/core/core.hpp>

namespace util{

	//! �摜����͂ݏo���`�̐��`
	cv::Rect TruncateRect(const cv::Rect& obj_rect, const cv::Size& img_size);

	//! �摜����͂ݏo���`�𒆐S���ێ����Ȃ��琮�`
	cv::Rect TruncateRectKeepCenter(const cv::Rect& obj_rect, const cv::Size& max_size);

	//! �A�m�e�[�V�����t�@�C���̓ǂݍ���
	/*!
	opencv_createsamles.exe�Ɠ��`���̃A�m�e�[�V�����t�@�C���ǂݏ���
	ReadCsvFile()�֐��K�{
	\param[in] gt_file �A�m�e�[�V�����t�@�C����
	\param[out] imgpathlist �摜�t�@�C���ւ̃p�X
	\param[out] rectlist �e�摜�ɂ���ꂽ�A�m�e�[�V�����̃��X�g
	\return �ǂݍ��݂̐���
	*/
	bool LoadAnnotationFile(std::string gt_file,
			std::vector<std::string>& imgpathlist,
			std::vector<std::vector<cv::Rect> >& rectlist);

	//! �A�m�e�[�V�����t�@�C���֒ǋL
	/*!
	opencv_createsamles.exe�Ɠ��`���̃A�m�e�[�V�����t�@�C���ǂݏ���
	\param[in] anno_file �A�m�e�[�V�����t�@�C����
	\param[in] img_file �摜�t�@�C���ւ̃p�X
	\param[int] obj_rects �e�摜�ɂ���ꂽ�A�m�e�[�V�����̃��X�g
	\return �ۑ��̐���
	*/
	bool AddAnnotationLine(const std::string anno_file,
			const std::string& img_file, const std::vector<cv::Rect>& obj_rects, const std::string& sep);

	// �f�B���N�g������摜�t�@�C�����ꗗ���擾
	bool ReadImageFilesInDirectory(const std::string& img_dir, std::vector<std::string>& image_lists);

	bool hasImageExtention(const std::string& filename);

	bool ReadCSVFile(const std::string input_file,
			std::vector<std::vector<std::string> > & output_strings,
		  const std::vector<std::string>& separater_vec = std::vector<std::string>());;

	std::vector<std::string> TokenizeString(const std::string& input_string, const std::vector<std::string>& separater_vec);
}

#endif

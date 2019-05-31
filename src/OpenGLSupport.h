/*
    Copyright 2016-2019 Arisotura

    This file is part of melonDS.

    melonDS is free software: you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by the Free
    Software Foundation, either version 3 of the License, or (at your option)
    any later version.

    melonDS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with melonDS. If not, see http://www.gnu.org/licenses/.
*/

#ifndef OPENGLSUPPORT_H
#define OPENGLSUPPORT_H

#include <stdio.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glext.h>

#include "Platform.h"


// here, have some macro magic
// we at the melonDS company really love macro magic
// also, suggestion to the fine folks who write the OpenGL headers:
// pls make the type names follow the same capitalization as their
// matching function names, so this is more convenient to deal with

#define DECLPROC(type, name)  \
    PFN##type##PROC _melonds_##name ;

#define DECLPROC_EXT(type, name)  \
    extern PFN##type##PROC _melonds_##name ;

#define LOADPROC(type, name)  \
    _melonds_##name = (PFN##type##PROC)Platform::GL_GetProcAddress(#name); \
    if (!_melonds_##name) { printf("OpenGL: " #name " not found\n"); return false; }


// if you need more OpenGL functions, add them to the macronator here
// TODO: handle conditionally loading certain functions for different GL versions

#ifndef __WIN32__

#define DO_PROCLIST_1_3(func) 

#else

#define DO_PROCLIST_1_3(func) \
    func(GLACTIVETEXTURE, glActiveTexture); \
    func(GLBLENDCOLOR, glBlendColor); \

#endif


#define DO_PROCLIST(func) \
    DO_PROCLIST_1_3(func) \
    \
    func(GLGENFRAMEBUFFERS, glGenFramebuffers); \
    func(GLDELETEFRAMEBUFFERS, glDeleteFramebuffers); \
    func(GLBINDFRAMEBUFFER, glBindFramebuffer); \
    func(GLFRAMEBUFFERTEXTURE, glFramebufferTexture); \
    func(GLBLITFRAMEBUFFER, glBlitFramebuffer); \
    func(GLCHECKFRAMEBUFFERSTATUS, glCheckFramebufferStatus); \
     \
    func(GLGENBUFFERS, glGenBuffers); \
    func(GLDELETEBUFFERS, glDeleteBuffers); \
    func(GLBINDBUFFER, glBindBuffer); \
    func(GLMAPBUFFER, glMapBuffer); \
    func(GLMAPBUFFERRANGE, glMapBufferRange); \
    func(GLUNMAPBUFFER, glUnmapBuffer); \
    func(GLBUFFERDATA, glBufferData); \
    func(GLBUFFERSUBDATA, glBufferSubData); \
    func(GLBINDBUFFERBASE, glBindBufferBase); \
     \
    func(GLGENVERTEXARRAYS, glGenVertexArrays); \
    func(GLDELETEVERTEXARRAYS, glDeleteVertexArrays); \
    func(GLBINDVERTEXARRAY, glBindVertexArray); \
    func(GLENABLEVERTEXATTRIBARRAY, glEnableVertexAttribArray); \
    func(GLDISABLEVERTEXATTRIBARRAY, glDisableVertexAttribArray); \
    func(GLVERTEXATTRIBPOINTER, glVertexAttribPointer); \
    func(GLVERTEXATTRIBIPOINTER, glVertexAttribIPointer); \
    func(GLBINDATTRIBLOCATION, glBindAttribLocation); \
    func(GLBINDFRAGDATALOCATION, glBindFragDataLocation); \
     \
    func(GLCREATESHADER, glCreateShader); \
    func(GLSHADERSOURCE, glShaderSource); \
    func(GLCOMPILESHADER, glCompileShader); \
    func(GLCREATEPROGRAM, glCreateProgram); \
    func(GLATTACHSHADER, glAttachShader); \
    func(GLLINKPROGRAM, glLinkProgram); \
    func(GLUSEPROGRAM, glUseProgram); \
    func(GLGETSHADERIV, glGetShaderiv); \
    func(GLGETSHADERINFOLOG, glGetShaderInfoLog); \
    func(GLGETPROGRAMIV, glGetProgramiv); \
    func(GLGETPROGRAMINFOLOG, glGetProgramInfoLog); \
    func(GLDELETESHADER, glDeleteShader); \
    func(GLDELETEPROGRAM, glDeleteProgram); \
     \
    func(GLUNIFORM1I, glUniform1i); \
    func(GLUNIFORM1UI, glUniform1ui); \
    func(GLUNIFORM4UI, glUniform4ui); \
    func(GLUNIFORMBLOCKBINDING, glUniformBlockBinding); \
    func(GLGETUNIFORMLOCATION, glGetUniformLocation); \
    func(GLGETUNIFORMBLOCKINDEX, glGetUniformBlockIndex); \
     \
    func(GLBINDIMAGETEXTURE, glBindImageTexture); \
     \
    func(GLDRAWBUFFERS, glDrawBuffers); \
     \
    func(GLBLENDFUNCSEPARATE, glBlendFuncSeparate); \
    func(GLBLENDEQUATIONSEPARATE, glBlendEquationSeparate); \
     \
    func(GLCOLORMASKI, glColorMaski); \
     \
    func(GLMEMORYBARRIER, glMemoryBarrier); \
     \
    func(GLGETSTRINGI, glGetStringi); \


DO_PROCLIST(DECLPROC_EXT);

#define glGenFramebuffers          _melonds_glGenFramebuffers
#define glDeleteFramebuffers       _melonds_glDeleteFramebuffers
#define glBindFramebuffer          _melonds_glBindFramebuffer
#define glFramebufferTexture       _melonds_glFramebufferTexture
#define glBlitFramebuffer          _melonds_glBlitFramebuffer
#define glCheckFramebufferStatus   _melonds_glCheckFramebufferStatus
#define glGenBuffers               _melonds_glGenBuffers
#define glDeleteBuffers            _melonds_glDeleteBuffers
#define glBindBuffer               _melonds_glBindBuffer
#define glMapBuffer                _melonds_glMapBuffer
#define glMapBufferRange           _melonds_glMapBufferRange
#define glUnmapBuffer              _melonds_glUnmapBuffer
#define glBufferData               _melonds_glBufferData
#define glBufferSubData            _melonds_glBufferSubData
#define glBindBufferBase           _melonds_glBindBufferBase
#define glGenVertexArrays          _melonds_glGenVertexArrays
#define glDeleteVertexArrays       _melonds_glDeleteVertexArrays
#define glBindVertexArray          _melonds_glBindVertexArray
#define glEnableVertexAttribArray  _melonds_glEnableVertexAttribArray
#define glDisableVertexAttribArray _melonds_glDisableVertexAttribArray
#define glVertexAttribPointer      _melonds_glVertexAttribPointer
#define glVertexAttribIPointer     _melonds_glVertexAttribIPointer
#define glBindAttribLocation       _melonds_glBindAttribLocation
#define glBindFragDataLocation     _melonds_glBindFragDataLocation
#define glCreateShader             _melonds_glCreateShader
#define glShaderSource             _melonds_glShaderSource
#define glCompileShader            _melonds_glCompileShader
#define glCreateProgram            _melonds_glCreateProgram
#define glAttachShader             _melonds_glAttachShader
#define glLinkProgram              _melonds_glLinkProgram
#define glUseProgram               _melonds_glUseProgram
#define glGetShaderiv              _melonds_glGetShaderiv
#define glGetShaderInfoLog         _melonds_glGetShaderInfoLog
#define glGetProgramiv             _melonds_glGetProgramiv
#define glGetProgramInfoLog        _melonds_glGetProgramInfoLog
#define glDeleteShader             _melonds_glDeleteShader
#define glDeleteProgram            _melonds_glDeleteProgram
#define glUniform1i                _melonds_glUniform1i
#define glUniform1ui               _melonds_glUniform1ui
#define glUniform4ui               _melonds_glUniform4ui
#define glUniformBlockBinding      _melonds_glUniformBlockBinding
#define glGetUniformLocation       _melonds_glGetUniformLocation
#define glGetUniformBlockIndex     _melonds_glGetUniformBlockIndex
#define glBindImageTexture         _melonds_glBindImageTexture
#define glDrawBuffers              _melonds_glDrawBuffers
#define glBlendFuncSeparate        _melonds_glBlendFuncSeparate
#define glBlendEquationSeparate    _melonds_glBlendEquationSeparate
#define glColorMaski               _melonds_glColorMaski
#define glMemoryBarrier            _melonds_glMemoryBarrier
#define glGetStringi               _melonds_glGetStringi


bool OpenGL_Init();

bool OpenGL_BuildShaderProgram(const char* vs, const char* fs, GLuint* ids, const char* name);
void OpenGL_DeleteShaderProgram(GLuint* ids);
void OpenGL_UseShaderProgram(GLuint* ids);

#endif // OPENGLSUPPORT_H
